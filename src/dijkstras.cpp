/*struct Node:

    int vertex

    int weight


struct Graph:

    list adjacencyList

    list distance

    list previous

    list visited


function dijkstra(source, graph):

    n = graph.adjacencyList.size()


    graph.distance.resize(n, INT_MAX)

    graph.previous.resize(n, -1)

    graph.visited.resize(n, false)


    priorityQueue pq

    pq.push(Node(source, 0))

    graph.distance[source] = 0


    while !pq.empty():

        current = pq.pop_top()


        u = current.vertex


        if graph.visited[u]:

            continue


        graph.visited[u] = true


        for each neighbor in graph.adjacencyList[u]:

            v = neighbor.vertex

            weight = neighbor.weight


            if !graph.visited[v] and graph.distance[u] + weight < graph.distance[v]:

                graph.distance[v] = graph.distance[u] + weight

                graph.previous[v] = u

                pq.push(Node(v, graph.distance[v]))

end function*/