#ifndef __EXPLODE_UNPKLITE_HH__
#define __EXPLODE_UNPKLITE_HH__

#include <stdint.h>
#include <stddef.h>
#include "explode/proper_export.hh"

namespace explode
{
  class input_exe_file;
  class output_exe_file;
  class input;
  
  class EXPLODE_API unpklite
  {
  public:
    explicit unpklite (input_exe_file& inp);

	static bool accept(input_exe_file& inp);

    void unpack (output_exe_file& oexe);
    
    uint32_t header_length () const;
    uint32_t decomp_size () const;
    uint32_t compressed_size () const;
    uint32_t decompressor_size () const;
    uint32_t data_offset () const;
    bool     uncompressed_region () const;
    bool     has_checksum () const;
    

	uint16_t ver_minor() const;
	uint16_t ver_major() const;
	bool     large_exe() const;
	bool     extended() const;
  private:
    void _read_parameters ();
  private:
    unpklite (const unpklite&);
    unpklite& operator = (const unpklite&);
  private:
    input&    m_file;
    input_exe_file& m_exe_file;
    
    uint32_t m_header_length;
    uint32_t m_decomp_size;
    uint32_t m_compressed_size;
    uint32_t m_decompressor_size;
    uint32_t m_data_offset;
    bool     m_uncompressed_region;
    bool     m_has_checksum;
    uint16_t m_h_pklite_info;

	uint16_t m_ver_minor;
	uint16_t m_ver_major;
	bool     m_extended;
	bool     m_large_exe;

  };
} // ns explode


#endif
