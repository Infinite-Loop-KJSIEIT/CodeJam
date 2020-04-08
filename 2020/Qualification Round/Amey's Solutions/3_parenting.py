class parent:
	def __init__(self):
		self.busy_until = 0

	def free(self, now):
		if(self.busy_until <= now):
			return(True)
		else:
			return(False)

	def assign(self, until):
		self.	busy_until = until

T = int(input())
for case in range(T):
	n = int(input())
	tasks = list()
	for _ in range(n):
	    tasks.append(list(map(int, input().split())))

	#Initialize parents.
	C = parent()
	J = parent()
	#Initialize schedule.
	schedule = [None] * len(tasks)

	for index, task in sorted(enumerate(tasks), key = lambda arr: arr[1][0]):		#Sort tasks in the order of begin-time and preserve the original index.
		now, until = task
		if(C.free(now)):
			C.assign(until)
			schedule[index] = 'C'

		elif(J.free(now)):
			J.assign(until)
			schedule[index] = 'J'

		else:
			schedule = "IMPOSSIBLE"
			break

	print("Case #{}: {}".format(case + 1, "".join(schedule)))