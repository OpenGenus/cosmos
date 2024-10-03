###Problem Link
[PROXYC](https://www.codechef.com/problems/PROXYC)

**Description**
Chef is a brilliant university student that does not attend lectures because he believes that they are boring and coding is life! However, his university follows certain rules and regulations, and a student may only take an exam for a course if he has attended at least 75% of lectures for this course.

Since you are Chef's best friend, you want to help him reach the attendance he needs to take exams. Unfortunately, Chef is still focused on his code and refuses to attend more lectures, so the only option is to have some of his friends mark him as present by proxy. This trick is well-known in the university, but only few have the talent to pull it off.

In a certain course, there is exactly one lesson per day over the course of D days (numbered 1 through D). You are given a string S with length D describing the lessons Chef attended — for each valid i, the i-th character of this string is either 'A' if Chef was absent on day i or 'P' if Chef was actually present on day i.

For each day d when Chef is absent, one of Chef's friends can mark him as present by proxy on this day only if he was present (if he was really present, not just marked as present) on at least one of the previous two days, i.e. days d−1 and d−2, and on at least one of the following two days, i.e. days d+1 and d+2. However, it is impossible to mark him as present by proxy on the first two days and the last two days.

Find the minimum number of times Chef has to be marked as present by proxy so that his attendance becomes at least 75% (0.75). Chef's attendance is number of days when he was marked as present, either by proxy or by actually being present, divided by D.