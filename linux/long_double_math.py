from ctypes import cdll, byref, c_long, c_double

lib_pamath = cdll.LoadLibrary("./long_double_math_core.so")
lib_pamath.sum_vec.restype = c_longdouble
lib_pamath.dot_vec.restype = c_longdouble
lib_pamath.cos_vec.restype = c_longdouble

def sum_vec(vl):
	ilen = len(vl)
	Vec = c_longdouble * ilen
	return lib_pamath.sum_vec(byref(Vec(*vl)), c_long(ilen))

def dot_vec(v1, v2):
	ilen = len(v1)
	Vec = c_longdouble * ilen
	return lib_pamath.dot_vec(byref(Vec(*v1)), byref(Vec(*v2)), c_long(ilen))

def cos_vec(v1, v2):
	ilen = len(v1)
	Vec = c_longdouble * ilen
	return lib_pamath.cos_vec(byref(Vec(*v1)), byref(Vec(*v2)), c_long(ilen))

def mul_vec(v1, v2):
	ilen = len(v1)
	Vec = c_longdouble * ilen
	vrs = Vec()
	lib_pamath.mul_vec(byref(Vec(*v1)), byref(Vec(*v2)), byref(vrs), c_long(ilen))
	return list(vrs)
