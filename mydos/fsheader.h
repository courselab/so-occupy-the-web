#ifndef FSHEADER_H
#define FSHEADER_H

#define FS_SIGLEN 4

struct fs_header_t
{
  unsigned char signature[FS_SIGLEN];     /* The file system signature.              */
  unsigned short total_number_of_sectors; /* Number of 512-byte disk blocks.         */
  unsigned short number_of_boot_sectors;  /* Sectors reserved for boot code.         */
  unsigned short number_of_file_entries;  /* Maximum number of files in the disk.    */
  unsigned short max_file_size;           /* Maximum size of a file in blocks.       */
  unsigned int unused_space;              /* Remaining space less than max_file_size.*/
} __attribute__((packed));      	  /* Disable alignment to preserve offsets.  */

#endif // FSHEADER_H
