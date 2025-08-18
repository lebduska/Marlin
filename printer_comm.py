import socket
import time
import sys

def send_command(sock, command):
    """Pošle příkaz a čeká na odpověď"""
    print(f"Posílám: {command}")
    try:
        sock.send(f"{command}\n".encode())
        time.sleep(0.5)
        
        response = ""
        timeout = 5
        start_time = time.time()
        
        while time.time() - start_time < timeout:
            try:
                sock.settimeout(0.1)
                data = sock.recv(1024).decode("utf-8", "ignore")
                if data:
                    response += data
                    print(f"Odpověď: {data.strip()}")
                    # Ukončí čekání, pokud dostaneme "ok" nebo "echo:busy: processing"
                    if "ok" in data or "echo:busy: processing" in data:
                        break
            except socket.timeout:
                continue
            except Exception as e:
                print(f"Chyba při čtení: {e}")
                break
                
    except Exception as e:
        print(f"Chyba při odesílání: {e}")
    
    return response

def sync_after_reset(sock):
    """Synchronizace po případném resetu"""
    print("Synchronizuji po případném resetu...")
    
    # Čekáme na start/ok
    sync_seen = False
    t0 = time.time()
    while time.time() - t0 < 3:
        try:
            sock.settimeout(0.1)
            data = sock.recv(1024).decode("utf-8", "ignore")
            if data:
                lines = data.strip().split('\n')
                for line in lines:
                    if line:
                        print(f"Boot: {line}")
                        if "start" in line.lower() or line == "ok":
                            sync_seen = True
                            break
                if sync_seen:
                    break
        except socket.timeout:
            continue
        except Exception as e:
            print(f"Chyba při synchronizaci: {e}")
            break
    
    if sync_seen:
        # Reset čítače příkazů
        print("Resetuji čítač příkazů...")
        try:
            sock.send(b"M110 N0\n")
            time.sleep(0.05)
            print("Synchronizace dokončena!")
        except Exception as e:
            print(f"Chyba při resetu čítače: {e}")
    else:
        print("Synchronizace selhala, ale pokračuji...")

def interactive_mode(sock):
    """Interaktivní režim - zůstane připojený"""
    print("Interaktivní režim - zadej G-code příkazy (nebo 'quit' pro ukončení):")
    print("Příklad: G28, M114, G1 X50 Y50")
    
    while True:
        try:
            command = input("> ").strip()
            if command.lower() in ['quit', 'exit', 'q']:
                break
            if command:
                send_command(sock, command)
        except KeyboardInterrupt:
            print("\nUkončuji...")
            break
        except EOFError:
            break

def main():
    try:
        # Vytvoření socket připojení k bridge
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(5)
        
        print(f"Připojuji k bridge: 127.0.0.1:9001")
        sock.connect(("127.0.0.1", 9001))
        
        print("Bridge připojení navázáno, čekám na stabilizaci...")
        time.sleep(1.0)
        
        if len(sys.argv) > 1:
            if sys.argv[1] == "interactive":
                # Interaktivní režim
                interactive_mode(sock)
            else:
                # Jeden příkaz
                send_command(sock, sys.argv[1])
        else:
            # Bez argumentů - interaktivní režim
            interactive_mode(sock)
        
        sock.close()
        print("Spojení ukončeno.")
        
    except socket.error as e:
        print(f"Chyba socket připojení: {e}")
        print("Tip: Zkontrolujte, zda:")
        print("1. Bridge je spuštěn na 127.0.0.1:9001")
        print("2. Tiskárna je připojena k bridge")
        print("3. Port není blokován firewall")
    except Exception as e:
        print(f"Chyba: {e}")

if __name__ == "__main__":
    main()
