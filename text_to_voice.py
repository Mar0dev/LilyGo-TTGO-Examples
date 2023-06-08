import os
from time import sleep
#check if pyttsx3 exists, if not, install it
try:
    import pyttsx3
except:
    os.system("pip install pyttsx3")
    import pyttsx3
        

#how much time you want to wait before speak
sleep(5)

text = 'you have been hacked ha ha ha ha ha ha ha ha ha ha ha'
motore = pyttsx3.init()
#voice settings
voice = motore.getProperty('voices')[1]
motore.setProperty('voice', voice.id)
motore.setProperty('pitch', 10)

#run the voice for X times
for _ in range(5):
    motore.say(text)
    motore.runAndWait()