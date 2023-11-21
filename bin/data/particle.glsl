# version 450
//TODO: Inlcude unifrorm for behavior matrix. 
struct Particle{
    vec2 pos;
    vec2 vel;
    vec4 col;
};
layout(binding = 0) buffer parts {Particle p[ ]; };
layout(local_size_x = 1000, local_size_y = 1, local_size_z = 1) in;


float per(float x, int nx) // periodic bnd’s
{
 if(x<0) x = nx-1;
 else 
 if(x>nx-1) x = 0;
 return x;
}


void main()
{
    int idx = int(gl_GlobalInvocationID.x);
    Particle particle = p[idx];
    particle.pos = particle.pos + particle.vel; //Get them moving somewhere.
    p[idx] = particle;
    
    
    
}
