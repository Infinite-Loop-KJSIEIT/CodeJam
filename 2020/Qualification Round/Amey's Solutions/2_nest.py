T = int(input())
for case in range(T):
	s = input()
	op = 0		#Open parantheses.
	s_ = ""
	
	for d in s:
		np = int(d) - op	#New parantheses.
		if(np > 0):
			s_ += "".join(['(' for _ in range(np)])		#Open more parantheses.
		else:
			s_ += "".join([')' for _ in range(-np)])	#Close extra parantheses.
		s_ += d
		op = int(d)

	s_ += "".join([')' for _ in range(op)])		#Close the reamaining parantheses.
	print("Case #{}: {}".format(case + 1, s_))