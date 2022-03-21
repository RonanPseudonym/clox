#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    init_vm();

    Chunk chunk;
    init_chunk(&chunk);

    int constant = add_constant(&chunk, 4.2);
    write_chunk(&chunk, OP_CONSTANT, 0);
    write_chunk(&chunk, constant, 0);

    constant = add_constant(&chunk, 3.4);
    write_chunk(&chunk, OP_CONSTANT, 0);
    write_chunk(&chunk, constant, 0);

    write_chunk(&chunk, OP_ADD, 0);

    constant = add_constant(&chunk, 5.6);
    write_chunk(&chunk, OP_CONSTANT, 0);
    write_chunk(&chunk, constant, 0);

    write_chunk(&chunk, OP_DIVIDE, 0);
    write_chunk(&chunk, OP_NEGATE, 0);
    write_chunk(&chunk, OP_RETURN, 0);
    disassemble_chunk(&chunk, "test chunk");
    interpret(&chunk);

    free_vm();
    free_chunk(&chunk);

    return 0;
}
