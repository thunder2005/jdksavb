#pragma once

/*
Copyright (c) 2014, Jeff Koftinoff
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the {organization} nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "jdksavb_world.h"
#include "jdksavb_adp_advertiser_signals.h"

#ifdef __cplusplus
extern "C" {
#endif

struct jdksavb_adp_advertiser_slots
{
    void ( *terminate )( struct jdksavb_adp_advertiser_slots *self );

    void ( *connect_signals )( struct jdksavb_adp_advertiser_slots *self,
                               struct jdksavb_adp_advertiser_signals *destination_signals );

    void ( *disconnect_signals )( struct jdksavb_adp_advertiser_slots *self,
                                  struct jdksavb_adp_advertiser_signals *destination_signals );

    void ( *set_adpdu )( struct jdksavb_adp_advertiser_slots *self, struct jdksavdecc_adpdu adpdu_params );

    void ( *gptp_gm_changed )( struct jdksavb_adp_advertiser_slots *self,
                               struct jdksavdecc_eui64 new_gtp_gm_id,
                               uint8_t new_gptp_domain_id );

    void ( *network_port_link_status_changed )( struct jdksavb_adp_advertiser_slots *self,
                                                struct jdksavdecc_eui48 mac_addr,
                                                bool up );

    void ( *start )( struct jdksavb_adp_advertiser_slots *self );

    void ( *stop )( struct jdksavb_adp_advertiser_slots *self );

    void ( *handle_pdu )( struct jdksavb_adp_advertiser_slots *self, struct jdksavb_frame *frame );

    void ( *tick )( struct jdksavb_adp_advertiser_slots *self, jdksavdecc_timestamp_in_microseconds current_time );
};

#ifdef __cplusplus
}
#endif
