# Import the os module, for the os.walk function
import os
 
# Set the directory you want to start from

for dirName, subdirList, fileList in os.walk('.'):
    print('Found directory: %s' % dirName)
    for fname in fileList:
        #print('\t%s' % fname)
        if(fname.endswith('.exe')):
        	st = dirName + "/" + fname
        	print('\t%s' %st)
        	os.remove(st)
        elif(fname.endswith('.out')):
        	st = dirName + "/" + fname
        	print('\t%s' %st)
        	os.remove(st)
