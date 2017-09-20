#!/usr/bin/env python3

import sys
import sqlite3
from PyQt5 import QtCore, QtGui, QtWidgets
from gui_frontend import Ui_MainWindow
from gui_ownerdog import Ui_verticalLayout1
from gui_eventinfo import Ui_PButtonCancel_2

class wndFrontEndGUI(QtWidgets.QMainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.do_connections()

    def do_connections(self):
        pass


if __name__ == "__main__":
    root = QtWidgets.QApplication(sys.argv)
    app = wndFrontEndGUI()
    app.show()
    root.exec_()
#    sys.exit(app.exec_())
