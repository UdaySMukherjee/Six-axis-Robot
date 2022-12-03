import RPi.GPIO as GPIO
import time

import pyttsx3
def voice():
    engine = pyttsx3.init()
    voices = engine.getProperty('voices')
    engine.setProperty('voice', voices[1].id)
    #print(voices[1].id)
    engine.setProperty('rate', 150)
    #engine.say("Hello, How are you ?")
    engine.runAndWait()

    def speak(str):
        engine.say(str)
        engine.runAndWait()

    speak("Hello, What's going on")

channel1=4
channel2=27

#GPIO Setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(channel1, GPIO.OUT)
GPIO.setup(channel2, GPIO.OUT)

def relay_on(pin):
    GPIO.output(pin,GPIO.HIGH)
    
def relay_off(pin):
    GPIO.output(pin,GPIO.LOW)
    
if __name__=='__main__':
    try:
        relay_on(channel1)
        time.sleep(1)
        relay_on(channel2)
        time.sleep(1)
        voice()
        relay_off(channel1)
        time.sleep(1)
        relay_off(channel2)
        time.sleep(1)
        
        GPIO.cleanup()
    except KeyboardInterrupt:
        GPIO.cleanup()
        pass