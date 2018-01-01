# Modular Arithmatic for Competitive Programming

If a is dividend, b is divisor, q is quoitent and r is remainder, then

````
a mod b = r
a / b = q
a = b*q + r
````

Here a mod b is only possible when both are integer and 0 <= r <= b-1

Division Rules:
````
If a | b and a | c, then a | (b + c)                (a | b : a divides b, i.e. b/a)
If a | b, then a | (b*c) for all integers c
If a | b and b | c, then a | c
````

Generally a mod m is the biggest multiple of m which is less than (or equal to) a. So,
````
-13 mod 3 = ?
as, -13 = 3*(-5) + 2
so, -13 mod 3 = 2                 (mod value is always positive)
````

## Congurency

Let a and b two integers such that a ≠ b, and m is co-prime of both a and b, and
````
a mod m = p
b mod m = q
````
Then a and b is congurent iff
````
p = q
so, a mod m = b mod m
written as, a ≡ b (mod m)
````
