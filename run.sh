if command -v qemu-system-i386 &> /dev/null
then
    qemu-system-i386 -kernel build/kernel
else
    echo "QEMU not found"
fi
