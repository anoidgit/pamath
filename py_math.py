from math import sqrt

def sum_vec(vl):
	sum = 0
	for vu in vl:
		sum += vu
	return sum

def mul_vec(v1, v2):
	return [v1u * v2u for v1u, v2u in zip(v1, v2)]

def dot_vec(v1, v2):
	return sum_vec(mul_vec(v1, v2))

def cos_vec(v1, v2):
	nv1 = dot_vec(v1, v1)
	nv2 = dot_vec(v2, v2)
	d = dot_vec(v1, v2)
	return d / sqrt(nv1 * nv2)
