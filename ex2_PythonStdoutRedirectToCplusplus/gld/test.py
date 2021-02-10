class Sout:
	def write(self, s):
		output(s)
	def flush(self):
		self.buff=''
		
import sys
from gld import *
from code import *
sys.stdout = Sout()
sys.stderr = Sout()
sys.stdin  = None
print ("test1")
print ("test2")
print ("test3")