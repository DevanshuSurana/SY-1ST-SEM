from tkinter import *
import tkinter.messagebox


class BMI:
    def __init__(self, root):
        self.root = root
        self.root.title("Body Mass Index")
        self.root.geometry("1350x800+0+0")
        self.root.configure(background='White')
        # ==================================Frames==========================#

        MainFrame = Frame(self.root, bd=20, width=1350, height=700, padx=10, pady=10, bg="Gray", relief=RIDGE)
        MainFrame.grid()

        LeftFrame = Frame(MainFrame, bd=10, width=600, height=600, padx=10, pady=13, bg="Gray", relief=RIDGE)
        LeftFrame.pack(side=LEFT)

        RightFrame = Frame(MainFrame, bd=10, width=560, height=600, padx=10, pady=10, relief=RIDGE)
        RightFrame.pack(side=RIGHT)
        # ==================================================================#

        LeftFrame0 = Frame(LeftFrame, bd=5, width=712, height=143, padx=5, bg="sky blue", relief=RIDGE)
        LeftFrame0.grid(row=0, column=0)
        LeftFrame1 = Frame(LeftFrame, bd=5, width=712, height=170, padx=5, pady=5, relief=RIDGE)
        LeftFrame1.grid(row=4, column=0)
        LeftFrame2 = Frame(LeftFrame, bd=5, width=712, height=168, padx=5, pady=6, relief=RIDGE)
        LeftFrame2.grid(row=2, column=0)
        LeftFrame3 = Frame(LeftFrame, bd=5, width=712, height=95, padx=5, pady=5, relief=RIDGE)
        LeftFrame3.grid(row=3, column=0)

        RightFrame0 = Frame(RightFrame, bd=5, width=522, height=200, padx=5, pady=2, relief=RIDGE)
        RightFrame0.grid(row=0, column=0)
        RightFrame1 = Frame(RightFrame, bd=5, width=522, height=280, padx=5, relief=RIDGE)
        RightFrame1.grid(row=1, column=0)
        RightFrame2 = Frame(RightFrame, bd=5, width=522, height=95, padx=5, pady=2, bg="Gray", relief=RIDGE)
        RightFrame2.grid(row=2, column=0)
        # ===================================================================#
        var1 = StringVar()
        var2 = StringVar()
        var3 = DoubleVar()
        var4 = DoubleVar()

        # ===================================================================#
        def iExit():
            iExit = tkinter.messagebox.askyesno("Body Mass Index", "Confirm if you want to exit")
            if iExit > 0:
                root.destroy()
                return

        def Reset():
            var1.set("")
            var2.set("")
            var3.set(0)
            var4.set(0)
            self.txtBMIResult.delete("1.0", END)

        def BMI_Cal():
            BHeight = (var1.get())
            BWeight = (var2.get())

            self.txtBMIResult.delete("1.0", END)
            if (BHeight.isdigit() or BWeight.isdigit()):
                BHeight = float(BHeight)
                BWeight = float(BWeight)
                BMI = float('%.2f' % (BWeight / (BHeight * BHeight)))
                self.txtBMIResult.insert(END, BMI)
                var3.set(BHeight)
                var4.set(BWeight)
                return True
            else:
                tkinter.messagebox.showwarning("Body Mass Index", "Division by zero is invalid, Enter a valid number")
                var1.set("")
                var2.set("")
                var3.set(0)
                var4.set(0)
                self.txtBMIResult.delete("1.0", END)

        # ===================================================================#
        self.lblTitle = Label(LeftFrame0, text="Body mass Index", padx=17, pady=4, bd=1, fg="#000000",
                              font=('Times New Roman', 40, 'bold'), bg="sky blue", width=20)
        self.lblTitle.pack()

        self.BodyHeight = Scale(RightFrame0, variable=var3, from_=1, to=5, length=507, tickinterval=1,
                                orient=HORIZONTAL, state=DISABLED, label="Height in Meters Square",
                                font=('Times New Roman', 10, 'bold'))
        self.BodyHeight.grid(row=1, column=0)

        self.BodyWeight = Scale(RightFrame2, variable=var4, from_=1, to=500, length=507, tickinterval=50,
                                orient=HORIZONTAL, state=DISABLED, label="Weight in Kilograms",
                                font=('Times New Roman', 10, 'bold'))
        self.BodyWeight.grid(row=1, column=0)

        self.lblBMITable = Label(RightFrame1, font=('Times New Roman', 20, 'bold'), text="\tBMI Table").grid(row=0,
                                                                                                             column=0)
        self.txtBMITable = Text(RightFrame1, height=12, width=53, bd=16, font=('Times New Roman', 12, 'bold'))
        self.txtBMITable.grid(row=1, column=0, columnspan=3)

        self.txtBMITable.insert(END, 'Meaning \t\t\t\t' + "BMI \n\n")
        self.txtBMITable.insert(END, 'Normal Weight \t\t\t\t' + "19 - 24.9 \n\n")
        self.txtBMITable.insert(END, 'Overweight \t\t\t\t' + "25 - 29.9 \n\n")
        self.txtBMITable.insert(END, 'Obesity level 1 \t\t\t\t' + "30 - 34 \n\n")
        self.txtBMITable.insert(END, 'Obesity level II \t\t\t\t' + "35 - 39.9 \n\n")
        self.txtBMITable.insert(END, 'Obesity level III \t\t\t\t' + "≥ 40 \n\n")
        # ===================================================================#
        self.lblHeight = Label(LeftFrame2, text="Enter Height in Meters Square: ", font=('Times New Roman', 20, 'bold'),
                               bd=2, justify=LEFT)
        self.lblHeight.grid(row=0, column=0, padx=15)
        self.txtHeight = Entry(LeftFrame2, textvariable=var1, font=('Times New Roman', 20, 'bold'), bd=5, width=15,
                               justify=LEFT)
        self.txtHeight.grid(row=0, column=1, pady=10)

        self.lblWeight = Label(LeftFrame2, text="Enter Weight in Kilograms: ", font=('Times New Roman', 20, 'bold'),
                               bd=2, justify=LEFT)
        self.lblWeight.grid(row=1, column=0)
        self.txtBodyWeight = Entry(LeftFrame2, textvariable=var2, font=('Times New Roman', 20, 'bold'), bd=5, width=15,
                                   justify=RIGHT)
        self.txtBodyWeight.grid(row=1, column=1, pady=10)

        self.lblBMIResult = Label(LeftFrame3, text="Your BMI Result is: ", font=('Times New Roman', 20, 'bold'), bd=2,
                                  justify=LEFT)
        self.lblBMIResult.grid(row=0, column=0)
        self.txtBMIResult = Text(LeftFrame3, padx=105, pady=5, font=('Times New Roman', 20, 'bold'), bd=5,
                                 bg="sky blue", relief='sunk', width=13, height=1)
        self.txtBMIResult.grid(row=0, column=1)
        # ===================================================================#
        self.btnBMI = Button(LeftFrame1, text="Calculate BMI", padx=4, pady=2, bd=4, width=12,
                             font=('Times New Roman', 20, 'bold'), height=4, command=BMI_Cal)
        self.btnBMI.grid(row=3, column=0)
        self.btnReset = Button(LeftFrame1, text="Reset", padx=4, pady=2, bd=4, width=12,
                               font=('Times New Roman', 20, 'bold'), height=4, command=Reset)
        self.btnReset.grid(row=3, column=1)
        self.btnExit = Button(LeftFrame1, text="Exit", padx=4, pady=2, bd=4, width=12,
                              font=('Times New Roman', 20, 'bold'), height=4, command=iExit)
        self.btnExit.grid(row=3, column=2)


if __name__ == '__main__':
    root = Tk()
    application = BMI(root)
    root.mainloop()