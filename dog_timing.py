#!/usr/bin/env python3

import sys
import sqlite3
from PyQt5 import QtCore, QtGui
from gui_frontend import Ui_MainWindow

class wndFrontEndGUI(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.do_connections()

    def do_connections(self):
        pass


if __name__ == "__main__":
    root = QtGui.QApplication(sys.argv)
    app = wndFrontEndGUI()
    app.show()
    root.exec_()
#    sys.exit(app.exec_())
