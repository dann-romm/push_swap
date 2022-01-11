import random
import os

# def do_instr(a: list, instr: int, temp1: list, temp2: list):
# 	if (instr == 0): # sa
# 		if (len(a) > 1):
# 			a[0] ^= a[1]
# 			a[1] ^= a[0]
# 			a[0] ^= a[1]
# 	elif (instr == 1): # sb
# 		if (len(temp1) > 1):
# 			temp1[0] ^= temp1[1]
# 			temp1[1] ^= temp1[0]
# 			temp1[0] ^= temp1[1]
# 	elif (instr == 2): # ra
# 		if (len(a) > 0):
# 			temp2.insert(0, a.pop(0))
# 	elif (instr == 3): # rra
# 		if (len(temp2) > 0):
# 			a.insert(0, temp2.pop(0))
# 	elif (instr == 4): # pb
# 		if (len(a) > 0):
# 			temp1.insert(0, a.pop(0))
# 	elif (instr == 5): # pa
# 		if (len(temp1) > 0):
# 			a.insert(0, temp1.pop(0))

# def minsort(a):
# 	if (a == [0, 1, 2, 3]):
# 		print()
# 		return
# 	for i0 in [0, 2, 4]:
# 		s1 = a.copy()
# 		t11 = []
# 		t12 = []
# 		do_instr(s1, i0, t11, t12)
# 		if (s1 == [0, 1, 2, 3]):
# 			print(i0)
# 			return
# 		for i1 in [0, 2, 4]:
# 			if ((i0 == 0 and i1 == 0) or (i0 == 9 - i1) or (i0 + i1 == 5 and (i0 == 2 or i0 == 3))):
# 				continue
# 			s2 = s1.copy()
# 			t21 = t11.copy()
# 			t22 = t12.copy()
# 			do_instr(s2, i1, t21, t22)
# 			if (s2 == [0, 1, 2, 3]):
# 				print(i0, i1)
# 				return
# 			for i2 in range(6):
# 				if ((i1 == 0 and i2 == 0) or (i1 == 9 - i2) or (i1 + i2 == 5 and (i1 == 2 or i2 == 3))):
# 					continue
# 				if (i2 == 1 and len(t21) < 2):
# 					continue
# 				s3 = s2.copy()
# 				t31 = t21.copy()
# 				t32 = t22.copy()
# 				do_instr(s3, i2, t31, t32)
# 				if (s3 == [0, 1, 2, 3]):
# 					print(i0, i1, i2)
# 					return
# 				for i3 in range(6):
# 					if ((i2 == 0 and i3 == 0) or (i2 == 9 - i3) or (i2 + i3 == 5 and (i2 == 2 or i3 == 3))):
# 						continue
# 					if (i3 == 1 and len(t31) < 2):
# 						continue
# 					s4 = s3.copy()
# 					t41 = t31.copy()
# 					t42 = t32.copy()
# 					do_instr(s4, i3, t41, t42)
# 					if (s4 == [0, 1, 2, 3]):
# 						print(i0, i1, i2, i3)
# 						return
# 					for i4 in range(6):
# 						if ((i3 == 0 and i4 == 0) or (i3 == 9 - i4) or (i3 + i4 == 5 and (i3 == 2 or i4 == 3))):
# 							continue
# 						if (i4 == 1 and len(t41) < 2):
# 							continue
# 						s5 = s4.copy()
# 						t51 = t41.copy()
# 						t52 = t42.copy()
# 						do_instr(s5, i4, t51, t52)
# 						if (s5 == [0, 1, 2, 3]):
# 							print(i0, i1, i2, i3, i4)
# 							return
# 						for i5 in range(6):
# 							if ((i4 == 0 and i5 == 0) or (i4 == 9 - i5) or (i4 + i5 == 5 and (i4 == 2 or i5 == 3))):
# 								continue
# 							if (i5 == 1 and len(t51) < 2):
# 								continue
# 							s6 = s5.copy()
# 							t61 = t51.copy()
# 							t62 = t52.copy()
# 							do_instr(s6, i5, t61, t62)
# 							if (s6 == [0, 1, 2, 3]):
# 								print(i0, i1, i2, i3, i4, i5)
# 								return
# 	print()

# found = False

# def minsort(depth, a, instr, t1, t2):
# 	global found
# 	if (found):
# 		return
# 	elif (a == [0, 1, 2, 3]):
# 		found = True
# 		print(instr)
# 		return
# 	elif (depth == 12):
# 		return
# 	if len(instr) > 1 and ((instr[-1] == 0 and instr[-2] == 0) or (instr[-1] + instr[-2] == 5 and (instr[-1] == 2 or instr[-2] == 3))):
# 		return
	
# 	for i in range(6):
# 		ac = a.copy()
# 		t1c = t1.copy()
# 		t2c = t2.copy()
# 		do_instr(ac, i, t1c, t2c)
# 		minsort(depth + 1, ac, instr + [i], t1c, t2c)


# def test():
# 	global found
# 	for i0 in range(4):
# 		for i1 in range(4):
# 			if (i1 == i0):
# 				continue
# 			for i2 in range(4):
# 				if (i2 == i1 or i2 == i0):
# 					continue
# 				i3 = 6 - i0 - i1 - i2

# 				print([i0, i1, i2, i3], "-> ", end="")
# 				found = False
# 				minsort(0, [i0, i1, i2, i3], [], [], [])

# test()

# length = 20
# s = list(range(length))
# random.shuffle(s)


# # s = [1, 5, 2, 7, 6, 8, 10, 9, 3, 4]
# a = s.copy()

# print(a)


# max_leave_in_a_stack = 0
# max_elements_to_stay = []
# instructions = 0

# for i in range(length):
# 	cur_leave_in_a_stack = 1
# 	cur_elements_to_stay = [a[0]]
# 	cur_value = a[0]
# 	cur_instructions = 0
	
# 	for j in range(1, length):
# 		if a[j] > cur_value:
# 			cur_value = a[j]
# 			cur_leave_in_a_stack += 1
# 			cur_elements_to_stay.append(a[j])
# 		else:
# 			cur_instructions = j
	
# 	if cur_leave_in_a_stack > max_leave_in_a_stack:
# 		max_leave_in_a_stack = cur_leave_in_a_stack
# 		max_elements_to_stay = cur_elements_to_stay.copy()
# 		instructions = cur_instructions
# 	elif (cur_leave_in_a_stack == max_leave_in_a_stack and cur_instructions < instructions):
# 		max_leave_in_a_stack = cur_leave_in_a_stack
# 		max_elements_to_stay = cur_elements_to_stay.copy()
# 		instructions = cur_instructions
		
# 	a = s[i + 1:] + s[:i + 1]

# for i in range(length):
# 	cur_leave_in_a_stack = 1
# 	cur_elements_to_stay = [a[0]]
# 	cur_value = a[0]
# 	cur_instructions = 0
	
# 	for j in range(1, length):

# 		if (j != length - 1 and a[j] == a[j + 1] + 1):
# 			a[j] ^= a[j + 1]
# 			a[j + 1] ^= a[j]
# 			a[j] ^= a[j + 1]
# 			cur_instructions += 1

# 		if a[j] == cur_value + 1:
# 			cur_value = a[j]
# 			cur_leave_in_a_stack += 1
# 			cur_elements_to_stay.append(a[j])
# 		cur_instructions += 1
	
# 	if cur_leave_in_a_stack > max_leave_in_a_stack:
# 		max_leave_in_a_stack = cur_leave_in_a_stack
# 		max_elements_to_stay = cur_elements_to_stay.copy()
# 		instructions = cur_instructions
# 	elif (cur_leave_in_a_stack == max_leave_in_a_stack and cur_instructions < instructions):
# 		max_leave_in_a_stack = cur_leave_in_a_stack
# 		max_elements_to_stay = cur_elements_to_stay.copy()
# 		instructions = cur_instructions
	
# 	a = s[i + 1:] + s[:i + 1]

# print("max_leave_in_a_stack:", max_leave_in_a_stack)
# print("max_elements_to_stay:", max_elements_to_stay)
# print("instructions:", instructions)










# def find_max_increasing(a, b, len_a):
# 	count_max = 0
# 	i = 0
# 	while (i < len_a):
# 		count_cur = 1
# 		value_cur = a[i]
# 		j = (i + 1) % len_a

# 		while (j != i):
# 			if (a[j] > value_cur):
# 				value_cur = a[j]
# 				count_cur += 1
# 			j = (j + 1) % len_a
# 		print(a[i], "->", count_cur)
# 		if (count_cur > count_max):
# 			count_max = count_cur
# 			stack_max = i
# 		i += 1
# 	print("max =", stack_max)
# 	return (stack_max)


# t_stack	*i;
# t_stack	*tmp;
# int		cur_value;

# tmp = state->a->prev;
# i = max_inc->next;
# cur_value = max_inc->value;
# while (i)
# {
# 	if (i->value > cur_value)
# 		cur_value = i->value;
# 	i = i->next;
# }
# while (state->a != max_inc)
# {
# 	if (state->a->next && state->a->value == state->a->next->value + 1)
# 	{
# 		add_instr(state, 2);
# 		sa(state, 1);
# 	}
# 	if (state->a->value > cur_value)
# 	{
# 		cur_value = state->a->value;
# 		add_instr(state, 5);
# 		ra(state, 1);
# 	}
# 	else
# 	{
# 		add_instr(state, 1);
# 		pa(state, 1);
# 	}
# }
# cur_value = max_inc->value;
# add_instr(state, 5);
# ra(state, 1);
# while (state->a != tmp)
# {
# 	if (state->a->next && state->a->value == state->a->next->value + 1)
# 	{
# 		add_instr(state, 2);
# 		sa(state, 1);
# 	}
# 	if (state->a->value > cur_value)
# 	{
# 		cur_value = state->a->value;
# 		add_instr(state, 5);
# 		ra(state, 1);
# 	}
# 	else
# 	{
# 		add_instr(state, 1);
# 		pa(state, 1);
# 	}
# }
# if (state->a->next && state->a->value == state->a->next->value + 1)
# {
# 	add_instr(state, 2);
# 	sa(state, 1);
# }
# if (state->a->value > cur_value)
# {
# 	cur_value = state->a->value;
# 	add_instr(state, 5);
# 	ra(state, 1);
# }
# else
# {
# 	add_instr(state, 1);
# 	pa(state, 1);
# }
# while (state->instr[state->size - 1] == 5)
# 	state->size--;
# return (0);

# def sa(a: list):
# 	print("sa")
# 	a[0], a[1] = a[1], a[0]

# def pb(a: list, b: list):
# 	print("pb")
# 	b.insert(0, a.pop(0))

# def ra(a: list):
# 	print("ra")
# 	a.append(a.pop(0))

# def fill_stack_b(a, b, len_a, max_inc):
# 	i = max_inc + 1
# 	cur_value = a[max_inc]
	
# 	while (i < len_a):
# 		if (a[i] > cur_value):
# 			cur_value = a[i]
# 		i += 1
	
# 	# print(cur_value) = 3
# 	# print(len_a - max_inc) = 3

# 	i = 0
# 	while (i < max_inc):
# 		if (a[0] == a[1] + 1):
# 			sa(a)
# 		if (a[0] > cur_value):
# 			cur_value = a[0]
# 			ra(a)
# 		else:
# 			pb(a, b)
# 		i += 1
	
# 	if (a[0] == a[1] + 1):
# 		sa(a)
# 	cur_value = a[0]
# 	ra(a)
# 	i += 1
	
# 	while (i < len_a):
# 		if (a[0] == a[1] + 1):
# 			sa(a)
# 		if (a[0] > cur_value):
# 			cur_value = a[0]
# 			ra(a)
# 		else:
# 			pb(a, b)
# 		i += 1

# 	print(a, b)


# a = [5, 4, 9, 10, 7, 1, 3, 2]
# b = []
# len_a = 8

# max_inc = find_max_increasing(a, b, len_a)
# print("\n", a, "\n")
# fill_stack_b(a, b, len_a, max_inc)

import random
import os

length = 7
repeats = 1
numbers = list(range(1, length + 1))

for i in range(repeats):
	# numbers = [random.randint(-2147483648, 2147483648) for _ in range(length)]
	# numbers = [random.randint(-1000, 1000) for _ in range(length)]
	random.shuffle(numbers)
	
	args = " ".join([str(x) for x in numbers])
	wcl = " | wc -l"
	os.system("./push_swap " + args)

	print("\t", numbers)
	# os.system("./push_swap " + args + wcl)
	os.system("ARG=\"" + args + "\"; ./push_swap $ARG | ./checker_Mac $ARG")
	# os.system("ARG=\"" + args + "\"; ./push_swap $ARG | ./checker $ARG")
	

# ошибки :')
[3, 1, 5, 4, 2]
[3, 1, 4, 5, 2]
[4, 2, 1, 5, 3]
[-887, -896, 316, 594, -909]
[-120, -301, 63, 117, -978]
[814, -706, 925, 873, -828]
[427, -81, -606, 580, -777]
[-8, 311, 120, -769, -651]
[7, 792, 50, -289, -416]
[-267, -555, -624, 151, -371]

# ./push_swap 6 2 4 7 3 1 5
