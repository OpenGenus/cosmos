#!/usr/bin/python
'''
General Structure:
function:
  switcher={
          case1: <condition1>
          case2: <condition2>
          case3: <condition3>
          .
          .
          .
  }

'''

def week(i):
        switcher={
                0:'Sunday',
                1:'Monday',
                2:'Tuesday',
                3:'Wednesday',
                4:'Thursday',
                5:'Friday',
                6:'Saturday'
             }
         return switcher.get(i,"Invalid day of week")
