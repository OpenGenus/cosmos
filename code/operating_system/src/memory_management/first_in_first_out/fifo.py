from queue import Queue
from collections import defaultdict as df


def fifo(frames, n, pages):

    # To represent dict of current pages.
    # We use defaultdict so that we
    # quickly check if a page is present
    # in dictionary or not.
    frames_dict = df(int)
    
    # To store the pages in FIFO manner
    indexes = Queue()
    
        # Start from initial page

    page_faults = 0
    
    for page in pages:
    
        # Check if the set can hold
        # more pages
        if len(frames_dict) < frames:
        
            # Insert it into set if not present
            # already which represents page fault
            if (frames_dict[page] == 0):
                frames_dict[page] = 1
                
                # Increment page fault
                page_faults += 1
                
                #Push the current page in the Queue
                indexes.put(page)
                
        # If the set is full then need to perform FIFO
        # i.e. remove the first page of the queue from
        # set and queue both and insert the current page
        else:
        
            # Check if current page is not
            # already present in the set
            if (frames_dict[page] == 0):
            
                # Pop the first element from the queue
                first_in = indexes.get()
                
                # Remove the current page i.e. set it's value to 0
                frames_dict[first_in] = 0

                # Add the page in frames_dict and indexes
                frames_dict[page] = 1
                indexes.put(page)
                
                # Increment the page fault by 1
                page_faults += 1

    #return the page faults
    return page_faults
    
    
if __name__ == "__main__":
    f = int(input("Enter the number of frames: "))
    n = int(input("Enter the number of pages followed by pages: "))
    
    pages = list(map(int, input().split()))
    page_faults = fifo(f, n, pages)
    print(page_faults)
