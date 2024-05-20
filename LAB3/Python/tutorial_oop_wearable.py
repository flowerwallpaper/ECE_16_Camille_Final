from ECE16Lib.Communication import Communication
from time import sleep

if __name__ == "__main__":
    com_port = "/dev/cu.usbserial-1410"
    baud_rate = 115200
    comms = Communication(com_port, baud_rate)

    comms.setup()
    comms.clear()
    sleep(2)

    for i in range(1, 31):
        message = f"{i} seconds"
        comms.send_message(message)
        sleep(1)
        try:
            response = comms.receive_message()
            if response:
                print(f"{response.strip()}")
        except UnicodeDecodeError:
            print("Received data could not be decoded")

    comms.close()
