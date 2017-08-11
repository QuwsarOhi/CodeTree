#!usr/bin/env python3

def get_total_cost_of_meal():
    # original meal price
    meal_cost = float(input())
    # tip percentage
    tip_percent = int(input())
    # tax percentage
    tax_percent = int(input())

    # Write your calculation code here
    tip = meal_cost * float(tip_percent/100.0) # calculate tip
    tax = meal_cost * float(tax_percent/100.0) # caclulate tax

    # cast the result of the rounding operation to an int and save it as total_cost 
    total_cost = int(round(meal_cost + tax + tip))
    
    return str(total_cost)

# Print your result
print("The total meal cost is " + get_total_cost_of_meal() + " dollars.")
