import threading

class FibonacciThread(threading.Thread):

    def __init__(self):
        super().__init__()

    def run(self):
        a, b = 0, 1
        for i in range(1, 10001):
            a, b = b, a + b
            print(a)

class SquareThread(threading.Thread):

    def __init__(self):
        super().__init__()

    def run(self):
        for i in range(1, 10001):
            print(i * i)

class CubeThread(threading.Thread):

    def __init__(self):
        super().__init__()

    def run(self):
        for i in range(1, 10001):
            print(i * i * i)

def main():
    fibonacci_thread = FibonacciThread()
    square_thread = SquareThread()
    cube_thread = CubeThread()
    fibonacci_thread.start()
    square_thread.start()
    cube_thread.start()

if __name__ == "__main__":
    main()
