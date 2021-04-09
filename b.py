for _ in range(int(input())):
	result = "2020"
	n = int(input())
	s = input()
	flag = 1
	for i in range(n-4):
		if(result == s[i:i+4]):
			flag = 0
			break
	if flag:
		print("YES")
	else:
		print("NO")