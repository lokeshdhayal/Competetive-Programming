while True:
	try:
		s = int(input())
		if(s == 0):
			print(0)
		elif(s == 1):
			print(1)
		else:
			print(2*s - 2)
	except EOFERROR:
		break;