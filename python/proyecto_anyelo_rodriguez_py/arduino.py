import serial
from tkinter import *
import tkinter as tk 

commPort = 'COM5'
ser = serial.Serial(commPort, baudrate = 9600, timeout = 1)

def pasa():
    ser.write(b'o')

def nopasa():
    ser.write(b'x')
