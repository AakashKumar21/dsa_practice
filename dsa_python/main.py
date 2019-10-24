from P_match import p_match as pm
from Queue import Queue


# exp = "[5-(4*6)+{3(6-4)[3]}]"
# if pm(exp):
#     print("Valid")
# else:
#     print("Invalid")

q = Queue("aakash")
q.insert_at_rear("GG")
q.insert_at_rear("ABC")
print (q.delete_from_front()) //TODO

print(q.get_front())
print(q.get_rear())