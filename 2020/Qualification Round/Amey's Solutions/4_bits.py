def complement(bits):
	if(type(bits) == list):
		bits_ = [1 - bit  if(bit != None) else None for bit in bits]
	else:
		bits_ =1 - bits
	return(bits_)

def fetch_bits(queries, bits, lbound, ubound, pivots):
	for q in range(queries // 2):
		if(ubound < len(bits)):			#Fail-safe protocol.
			bits[ubound] = int(input(str(ubound + 1) + '\n'))
			bits[lbound] = int(input(str(lbound + 1) + '\n'))

			if(None in pivots):		#Discover pivotal points in the bits string. Stop once found.
				if(bits[ubound] == bits[lbound]):
					pivots[0] = lbound
					pivots[1] = ubound
				else:
					pivots[2] = lbound
					pivots[3] = ubound

			lbound -= 1
			ubound += 1

		else:
			break
	return(lbound, ubound)

if __name__ == "__main__":
	T, B = list(map(int, input().split()))
	for case in range(T):
		bits = [None] * B
		ubound = B // 2
		lbound = ubound - 1
		
		pivots = [None] * 4		#Pivots can be any pair of bits which are equidistant from the center and satisfy (P1 = P2 & P3 != P4). They help to identify fluctuations.
		lbound, ubound = fetch_bits(10, bits, lbound, ubound, pivots)		#Fetch first 10 bits.

		while(None in bits):			#Finishing condition
			queries = 0
			if(None in pivots):													#Palindrome string (reversal is pointless).
				index = [p for p in pivots if(p != None)]				#Remove None values.
				sample = int(input(str(index[0] + 1) + '\n'))		#Query a known position.
				if(sample != bits[index[0]]):								#Bits complemented. Else, bits are unchanged.
					bits = complement(bits)									#Complement the bits.
				queries = 8
				
				print(1)
				_ = input()					#Finish the ten queries.

			else:
				pivot_ref = [bits[p] for p in [pivots[0], pivots[2]]]
				pivot_new = [int(input(str(p + 1) + "\n")) for p in [pivots[0], pivots[2]]]

				if(complement(pivot_new) == pivot_ref):		#Bits complemented.
					bits = complement(bits)					#Complement the bits.

				elif([pivot_new[0], complement(pivot_new[1])] == pivot_ref):					#Bits reversed.
					bits.reverse()					#Reverse the bits.

				elif([complement(pivot_new[0]), pivot_new[1]] == pivot_ref):		#Bits reversed and complemented.
					#Complement and reverse the bits.
					bits = complement(bits)
					bits.reverse()

				elif(pivot_new == pivot_ref):		#No change.
					pass

				else:
					print("Damn!\nNot supposed to be here.")
				
				queries = 8

			lbound, ubound = fetch_bits(queries, bits, lbound, ubound, pivots)		#Fetch next bits.

		result = input("".join(map(str, bits)) + '\n')
		if(result == 'N'):
			break

#DEBUG.
'''
with open("debug.txt", 'a') as debug:
	debug.write("bits: " + " ".join([str(p) if(p != None) else "-" for p in bits]) + "\n")
'''