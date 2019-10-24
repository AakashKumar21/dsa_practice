from P_match import p_match as pm
from Queue import Queue


# exp = "[5-(4*6)+{3(6-4)[3]}]"
# if pm(exp):
#     print("Valid")
# else:
#     print("Invalid")

q = Queue("1")
q.insert_at_rear("2")
q.insert_at_rear("3")
q.insert_at_rear("4")

print (q.delete_from_front()) #TODO FIX

print(q.get_front())
print(q.get_rear())