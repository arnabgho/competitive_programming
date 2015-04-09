for (int step = 0; step <= n + 1; ++step)
    {
      for (int a = 0; a < n; ++a)
        for (int b = 0; b < n; ++b)
          if (adjacencyMatrix[a][b] == '1' && deg[a] <= deg[b] && deg[a] >= minDeg && deg[b] <= maxDeg && d[b] > d[a] - 1)
          {
            d[b] = d[a] - 1;
            if (step == n + 1)
              return -1;
          }
    } 