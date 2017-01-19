#from float_pamath import *
#from double_pamath import *
#from long_double_pamath import *

#from float_math import *
#from double_math import *
#from long_double_math import *

from py_math import *

from tqdm import tqdm

li=[float(i+1)/4096 for i in xrange(8192)]
for i in tqdm(xrange(100)):
	sum_vec(li)
	dot_vec(li,li)
	cos_vec(li,li)
	mul_vec(li,li)
