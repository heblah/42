export function clamp(num: number, min: number, max: number): number {
    return Math.min(Math.max(num, min), max);
}

export class Vector2D {
    public x: number = 0
    public y: number = 0

    constructor(x: number, y: number) {
        this.x = x
        this.y = y
    }
    
    // Add a vector to this vector
    add(v: Vector2D) {
      this.x += v.x;
      this.y += v.y;
    }
  
    // Subtract a vector from this vector
    sub(v: Vector2D) {
      this.x -= v.x;
      this.y -= v.y;
    }
  
    // Scale this vector by a value
    scale(s: number) {
      this.x *= s;
      this.y *= s;
    }
  
    // Calculate the dot product of this vector and another
    dot(v: Vector2D) {
      return this.x * v.x + this.y * v.y;
    }
  
    // Calculate the magnitude of this vector
    magnitude() {
      return Math.sqrt(this.x ** 2 + this.y ** 2);
    }
  
    // Normalize this vector (make its magnitude 1)
    normalize() {
      const magnitude = this.magnitude();
      if (magnitude > 0) {
        this.scale(1 / magnitude);
      }
    }
  }