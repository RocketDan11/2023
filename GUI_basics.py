import tkinter as tk

#create an instance of the Tk() class,
#this will serve as my main window.
window = tk.Tk()


#Creating widgets within the window (label, button)
#pack() method is used to add the widget to window
#automatically position it.
label = tk.Label(window, text = 'Hello World!')
label.pack()

button = tk.Button(window, text = "Click Me!")
button.pack()

#Handling events, button click using command parameter

def button_click():
    print("Button Clicked")
    
button = tk.Button(window, text = 'Click Me!', command = button_click)
button.pack()

#to start application, call mainloop()
window.mainloop()