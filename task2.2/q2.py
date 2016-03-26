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
Nx=100
T=1000000
Nt=1000
T1=10000
Nt1=5000
T2=100
Nt2=1000000
x = np.linspace(0, T, Nt, endpoint=True)
x1 = np.linspace(0,T1,Nt1,endpoint=True)
x2 = np.linspace(0,1,Nx+1,endpoint=True)
command = "./q2 1 {} {} {} 1 0 0".format(Nx,T,Nt).split()
command1 = "./q2 1 {} {} {} 1 0 0".format(Nx,T1,Nt1).split()
command2 = "./q2.2 1 {} {} {} 1 0 0" .format(Nx,T2,Nt2).split()
abc = run_command(command)[0].split()
abc1 = run_command (command1)[0].split()
# for symbol in abc:
	# print x
abc2 = run_command (command2)[0].split()
fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(10, 6))
axes[0].plot(x,abc)
# axes[1].plot(x1,abc1)
axes[1].plot(x2,abc2)
fig.tight_layout() 
pylab.show()



#pipe = Popen("./q2 1 10 10000 1000 1 0 0", shell=True, bufsize=bufsize, stdout=PIPE).stdout