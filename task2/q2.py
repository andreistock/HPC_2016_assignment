import subprocess,sys
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pylab

def run_command(command):
    return subprocess.Popen(command,
                         stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT).communicate()


subprocess.call(["ls", "-l"])
Nx=20
T=10000
Nt=100000000
Nt1=1000
T1=200000
x = np.linspace(0, T, Nt, endpoint=True)
x1 = np.linspace(0,T1,Nt1,endpoint=True)

command = "./q2 1 {} {} {} 1 0 0".format(Nx,T,Nt).split()
command1 = "./q2 1 {} {} {} 1 0 0".format(Nx,T1,Nt1).split()
abc = run_command(command)[0].split()
abc1 = run_command (command1)[0].split()
# for symbol in abc:
	# print symbol
fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(10, 6))
axes[0].plot(x,abc)
axes[1].plot(x1,abc1)
fig.tight_layout() 
pylab.show()



#pipe = Popen("./q2 1 10 10000 1000 1 0 0", shell=True, bufsize=bufsize, stdout=PIPE).stdout