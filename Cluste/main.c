#include <stdio.h>
#include <stdbool.h>

#define MAX_DUGUM 100

int adj[MAX_DUGUM][MAX_DUGUM];
int ziyaretEdildi[MAX_DUGUM];
int dugumSayisi;

void graphOlustur(int n) {
    dugumSayisi = n;
    for (int i = 0; i < n; i++) {
        ziyaretEdildi[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

void kenarEkle(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void DFS(int u, int clusterID) {
    ziyaretEdildi[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < dugumSayisi; v++) {
        if (adj[u][v] == 1 && ziyaretEdildi[v] == 0) {
            DFS(v, clusterID);
        }
    }
}

void kumele() {
    int clusterSayaci = 1;

    for (int i = 0; i < dugumSayisi; i++) {
        if (ziyaretEdildi[i] == 0) {
            printf("Cluster %d: { ", clusterSayaci);
            DFS(i, clusterSayaci);
            printf("}\n");
            clusterSayaci++;
        }
    }
}

int main() {
    graphOlustur(9);

    kenarEkle(0, 1);
    kenarEkle(1, 2);

    kenarEkle(3, 4);
    kenarEkle(4, 5);
    kenarEkle(3, 5);

    kenarEkle(6, 7);
    kenarEkle(7, 8);

    printf("Graph'taki Kumeler (Clusters):\n----------------------------\n");
    kumele();

    return 0;
}
