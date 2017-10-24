/*
	towerofhanoi.py
	by AP (@theashwin)
	
	Path of Cosmos by OpenGenus Foundation
*/

def moveTower(height,fromPole, toPole, withPole):
    if height >= 1:
        print( "    "*(3-height), "moveTower:", height, fromPole, toPole )
        moveTower(height-1,fromPole,withPole,toPole)
        moveDisk(fromPole,toPole,height)
        moveTower(height-1,withPole,toPole,fromPole)
    #print(withPole)

def moveDisk(fp,tp,height):
    print("    "*(4-height), "moving disk", "~"*(height), "from",fp,"to",tp)


moveTower(3,"A","B","C")
