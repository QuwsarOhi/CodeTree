# UVa
# 10281 - Average Speed

from sys import stdin, stdout

#stdin = open('in', 'r')
#stdout = open('out', 'w')

def printf(x):
	stdout.write(str(x) + '\n')

def Com(x):
	return x[0]

def main():
	inp = list(map(str.strip, stdin.readlines()))
	data = []
	for _ in inp:
		y = _.split()
		if len(y) == 2:
			h, m, s = map(int, y[0].split(':'))
			Time = h * 3600 + m * 60 + s
			data.append([Time, int(y[1])])
			data.sort(key=Com)
			#print('data append', Time)
		else:
			h, m, s = map(int, y[0].split(':'))
			Time = h * 3600 + m * 60 + s
			distance = 0
			if len(data) >= 1:
				ft, fv = data[0]
			else:
				#print('in else')
				print('%s %.2f km' %(y[0], distance))
				continue
			for st, sv in data[1:]:
				if st > Time:
					break
				distance += ((st - ft) * fv)/3600.0
				ft = st
				fv = sv
			distance += ((Time - ft) * fv)/3600.0
			print('%s %.2f km' %(y[0], distance)) 
if __name__ == '__main__':
	main()
