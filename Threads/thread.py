import threading
import time

def incrementar(n, numero):
    for i in range(100):
        print(f'Thread {n}: Contagem: {i + numero}\n')
        time.sleep(2)

thread1 = threading.Thread(target=incrementar, args=(1, 1))
thread2 = threading.Thread(target=incrementar, args=(2, 3))

thread1.start()
thread2.start()

thread1.join()
thread2.join()