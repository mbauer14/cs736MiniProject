import csv
import matplotlib.pyplot as plt
import numpy as np



if __name__ == '__main__':
    
    types = ['pipe', 'tcp', 'sharedMemory']
    data = {'latency': 
                    {'pipe': [], 'tcp': [], 'sharedMemory': []},
            'throughput':
                    {'pipe': [], 'tcp': [], 'sharedMemory': []}
            }


    sizes = [4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 524288] 

    # Parse all the data from the different files   
    for t in types:
        for s in sizes:
            pathname = '%s/%s_latency_%s.txt' % (t, t, s)

            f = open(pathname, 'r')


            latency = f.readlines()
            latency = [float(time) for time in latency]
            
 
            # find the minimum latency for better representation, convert to milliseconds
            #minLatency = min(latency) / 1000000
            minLatency = min(latency) /1000
            # throughput (in bytes/second) 
            minThroughput = s / minLatency

            data['latency'][t].append(minLatency)
            data['throughput'][t].append(minThroughput) 

            f.close()

    measures = ['latency', 'throughput']

    # Output as a csv file for easy access in excel or something
    for t in types:
        for m in measures:
            pathname = 'testing/%s_%s.csv' % (t, m)

            f = open(pathname, 'wb')
            writer = csv.writer(f)
 
            combined = zip(sizes, data[m][t])

            writer.writerows(combined)
            f.close()
            


    # Perform the plotting
    params = {'legend.fontsize': 10,
              'legend.labelspacing': 0.25}
    plt.rcParams.update(params)   
 
    colors = {'pipe': '#FF0000', 
            'tcp': '#0000FF', 
            'sharedMemory': '#33CC33'}

    ylabel = {'latency': 'Latency (in us)', 
            'throughput': 'Throughput (in bytes/us)'}

    titles = {'latency': 'Buffer Size vs Latency', 
            'throughput': 'Buffer Size vs Throughput'}
   
    labels = {'pipe': 'Pipe', 
            'tcp': 'Socket', 
            'sharedMemory': 'Shared Memory'}

 
    for m in measures:
        for t in types:
            plt.scatter(sizes, data[m][t], c=colors[t], s=30.0, label='%s' % labels[t])
 
        plt.title('%s' % titles[m])
        #plt.yscale('log')
        plt.xscale('log')
        plt.legend(loc=2)

        plt.xlabel("Size of Buffer (in bytes)")
        plt.ylabel(ylabel[m])
        plt.savefig('testing/nolog%s.png' % m, dpi=300)
        plt.clf() 

    plt.close()
