let endian = () => {
    let uInt32 = new Uint32Array([0x33883366]); //creating a 32 bit array and initializing it with arbitrary value
    let uInt8 = new Uint8Array(uInt32.buffer); //mapping the 32 bit array to 8 bit array
 
    if(uInt8[0] === 0x66) { //reading the first 4 bytes and determining endianness
        return 'Little Endian';
    } else {
        return 'Big Endian';
    }
};
 
endian();
