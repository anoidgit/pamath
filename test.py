#from float_pamath import *
#from double_pamath import *
#from long_double_pamath import *
from py_pamath import *
from tqdm import tqdm

li=[float(i+1)/1024 for i in xrange(1024)]
for i in tqdm(xrange(1000)):
	sum_vec(li)
	dot_vec(li,li)
	cos_vec(li,li)
	mul_vec(li,li)
