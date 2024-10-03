/**
 * Represents a clustering using the k-means algorithm.
 * Uses Eucledian distance by default
 * but the user may provide a custom distance function
 */
export default class KMeans {
    /**
     * Creates a new instance of the KMeans class
     * @param k Number of clusters to find
     * @param distance The distance function to use. Defaults to Euclidean distance
     */
    constructor(private k: number, distance?: (a: number[], b: number[]) => number) {
        this.distanceFunc = distance ? distance : this.calculateEuclideanDistance;
    }

    /**
     * The cluster centroids
     */
    private centroids: number[][];

    /**
     * The distance function to use
     */
    private distanceFunc: (a: number[], b: number[]) => number;

    /**
     * Performs k-means clustering on the given points
     * @param points The points to initialize
     * @param initialCentroids The initial centroids. Optional.
     *     If none are provided, uses random initialization
     */
    fit(points: number[][], initialCentroids?: number[][]): number[][][] {
        // TODO: validate points & initial c.
        if (!initialCentroids) {
            initialCentroids = this.generateRandomCentroids(points);
        }

        this.centroids = initialCentroids;

        let clusterAssignments: number[] = new Array<number>(points.length);
        let clusterContents: number[][][] = new Array<number[][]>(this.k);

        let clusteringConverged: boolean = false;

        while (!clusteringConverged) {
            // Assign closest centroids
            points.forEach((point, i) => {
                clusterAssignments[i] = this.predict(point);
            });

            clusteringConverged = true;
            for (let clusterIndex: number = 0; clusterIndex < this.k; clusterIndex++) {
                let pointsInCluster: number[][] = clusterAssignments
                    .map((c, i) => c === clusterIndex ? points[i] : null)
                    .filter(p => p !== null);

                if (pointsInCluster.length === 0) {
                    continue;
                }

                let centroid: number[] = this.centroids[clusterIndex];
                let newCentroid: number[] = new Array(centroid.length);

                for (let centroidCoord: number = 0; centroidCoord < centroid.length; centroidCoord++) {
                    let sum: number = 0;
                    for (let pointCoord: number = 0; pointCoord < pointsInCluster.length; pointCoord++) {
                        sum += pointsInCluster[pointCoord][centroidCoord];
                    }
                    newCentroid[centroidCoord] = sum / pointsInCluster.length;

                    if (newCentroid[centroidCoord] !== centroid[centroidCoord]) {
                        clusteringConverged = false;
                    }
                }

                this.centroids[clusterIndex] = newCentroid;
                clusterContents[clusterIndex] = pointsInCluster;
            }
        }

        return clusterContents;
    }

    /**
     * Returns the index of the cluster of the given point
     * @param point The point to classify
     * @param distance The distance function
     */
    predict(point: number[]): number {
        let minDistance: number = Infinity;
        let closestClusterIndex: number = 0;
        this.centroids.forEach((centroid, i) => {
            let distanceToCentroid: number = this.distanceFunc(point, centroid);
            if (distanceToCentroid < minDistance) {
                minDistance = distanceToCentroid;
                closestClusterIndex = i;
            }
        });

        return closestClusterIndex;
    }

    /**
     * Chooses random k points as initial centroids
     * @param points The points to choose from
     */
    private generateRandomCentroids(points: number[][]): number[][] {
        let centroids: number[][] = points.slice(); // Copy the original array
        centroids.sort(() => {
            return Math.round(Math.random()) - 0.5;
        });

        return centroids.slice(0, this.k);
    }

    /**
     * Calculates the Euclidean distance between two vectors. They can have
     * an arbitrary number of dimensions. The only requirement is that the dimensions
     * are the same
     * @param a The first vector
     * @param b The second vector
     */
    private calculateEuclideanDistance(a: number[], b: number[]): number {
        if (a.length !== b.length) {
            throw new Error("The dimensions of the two vectors are not the same");
        }

        let distance: number = 0;
        for (let i: number = 0; i < a.length; i++) {
            distance += Math.pow(b[i] - a[i], 2);
        }

        return distance;
    }
}

// Testing
let kMeans: KMeans = new KMeans(3);
let data: number[][] = [
    [1, 1, 1],
    [2, 2, 2],
    [3, 3, 3],
    [4, 4, 4],
    [5, 5, 5],
    [50, 50, 50],
    [1000, 1000, 1000]
];

let centroids: number[][][] = kMeans.fit(data);
console.log(JSON.stringify(centroids));
let newPoint: number[] = [30, 30, 30];
let closest: number = kMeans.predict(newPoint);
console.log(closest);