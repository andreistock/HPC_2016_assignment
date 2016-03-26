import subprocess,sys
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pylab

def run_command(command):
    return subprocess.Popen(command,
                         stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT).communicate()

Nx=20
T=10000
Nt=10000
T1=10000
Nt1=10000

T2=10000 # Time chosen for delta_x study
Nt2=100000 # Time discretisation for delta_x study
T3=10000 # Time chosen for delta_t study
Nx3=20 # Space discretisation for delta_t study
Nt3=1000 #Range of testing delta_t
x = np.linspace(0, T, Nt, endpoint=True)
x1 = np.linspace(0,1,Nx+1,endpoint=True)
x2 = np.linspace(0,1,Nx,endpoint=True)
x3 = np.linspace(0,T3,Nt3,endpoint=True)
command = "./q2 1 {} {} {} 1 0 0".format(Nx,T,Nt).split()
command1 = "./q2.2 1 {} {} {} 1 0 0".format(Nx,T1,Nt1).split()

abc = run_command(command)[0].split()
abc1 = run_command(command1)[0].split()
abc2 = np.array([])
abc3 = np.array([])
# for j in abc1:
	# print j
############# Calculate RMS error of proper solution #############
for i in xrange(1,Nx+1,1):
	command2 = "./q2.3 1 {} {} {} 1 0 0" .format(i,T2,Nt2).split()
	item = run_command (command2)[0].split()
	abc2 = np.append(abc2,item)

for i in xrange(1,Nt3+1,1):
	if i%1000 == 0:
		print i
	command2 = "./q2.3 1 {} {} {} 1 0 0" .format(Nx3,T3,i).split()
	item = run_command (command2)[0].split()
	abc3 = np.append(abc3,item)
    

print abc3
fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(10, 6))
axes[0].plot(x,abc)
axes[1].plot(x1,abc1)
fig.tight_layout() 
fig2, axes2 = plt.subplots(nrows=1, ncols=2, figsize=(10, 6))

axes2[0].plot(x2,abc2)

axes2[1].plot(x3,abc3)
xrange1=np.array([0,0.3])
# axes2[1].set_ylim([-100,100])
pylab.show()



#pipe = Popen("./q2 1 10 10000 1000 1 0 0", shell=True, bufsize=bufsize, stdout=PIPE).stdout