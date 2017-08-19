import numpy as np

# Input 9 numbers
s = np.array(input().strip().split(' '), int)

# Print 3 x 3 matrix
# Note : s array is still in old shape
print(np.reshape(s, (3, 3)))

##
# Another way is using shape
# In this way, the main array is changed
#
# s.shape = (3, 3)
# print(s)
##
