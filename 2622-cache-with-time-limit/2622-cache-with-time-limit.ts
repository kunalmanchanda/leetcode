class TimeLimitedCache {
    maps;

    constructor() {
        this.maps = new Map();
    }

    set(key: number, value: number, duration: number): boolean {
        let flag = false;

        if (this.maps.has(key)) {
            const timeoutId = this.maps.get(key)[1];
            clearTimeout(timeoutId);
            flag = true;
        }

        let timeoutId = setTimeout(() => {
            this.maps.delete(key);
        }, duration)
        this.maps.set(key, [value, timeoutId]);

        return flag;
    }

    get(key: number): number {
        if (this.maps.has(key)) {
            return this.maps.get(key)[0];
        }

        return -1;
    }

    count(): number {
        return this.maps.size;
    }
}

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */