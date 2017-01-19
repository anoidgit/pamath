from ctypes import cdll, pointer, c_long, c_float

lib_pamath = cdll.LoadLibrary("./float_pamath_core.so")
lib_pamath.sum_vec.restype = c_float
lib_pamath.dot_vec.restype = c_float
lib_pamath.cos_vec.restype = c_float

def copyl(lin, ai):
	curid = 0
	for lu in lin:
		ai[curid] = lu
		curid += 1

def genl(vi, vlen):
	return [vi[i] for i in xrange(vlen)]

def sum_vec(vl):
	vlen = c_long(len(vl))
	ilen = len(vl)
	vi = (c_float * ilen)()
	copyl(vl, vi)
	return lib_pamath.sum_vec(pointer(vi), vlen)

def dot_vec(v1, v2):
	vlen = c_long(len(v1))
	ilen = len(v1)
	vi1 = (c_float * ilen)()
	copyl(v1, vi1)
	vi2 = (c_float * ilen)()
	copyl(v2, vi2)
	return lib_pamath.dot_vec(pointer(vi1), pointer(vi2), vlen)

def cos_vec(v1, v2):
	vlen = c_long(len(v1))
	ilen = len(v1)
	vi1 = (c_float * ilen)()
	copyl(v1, vi1)
	vi2 = (c_float * ilen)()
	copyl(v2, vi2)
	return lib_pamath.cos_vec(pointer(vi1), pointer(vi2), vlen)

def mul_vec(v1, v2):
	vlen = c_long(len(v1))
	ilen = len(v1)
	vi1 = (c_float * ilen)()
	copyl(v1, vi1)
	vi2 = (c_float * ilen)()
	copyl(v2, vi2)
	vrs = (c_float * ilen)()
	lib_pamath.mul_vec(pointer(vi1), pointer(vi2), pointer(vrs), vlen)
	return genl(vrs, ilen)