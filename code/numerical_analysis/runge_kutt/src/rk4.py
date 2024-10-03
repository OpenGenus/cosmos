import math


def runge_kutt(start_conditions, finish_interval, step, f):
    res = []
    res_x = start_conditions[0]
    res_y = start_conditions[1]
    while res_x < finish_interval:
        res.append((res_x, res_y))
        k1 = step * f(res_x, res_y)
        k2 = step * f(res_x + step / 2.0, res_y + k1 / 2.0)
        k3 = step * f(res_x + step / 2.0, res_y + k2 / 2.0)
        k4 = step * f(res_x + step, res_y + k3)
        res_y += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0
        res_x += step
    return res


print("Enter start condition: ")
x0 = float(input("X= "))
y0 = float(input("Y= "))
st_cond = [x0, y0]
fin_int = float(input("Enter finish interval: "))
stp = float(input("Enter step: "))
res = runge_kutt(
    st_cond,
    fin_int,
    stp,
    lambda x, y: math.pow(x, 2) * (3 * y + math.exp(math.pow(x, 3))),
)
for result_x, result_y in res:
    print("X= %8.6f, Y= %8.6f" % (result_x, result_y))
