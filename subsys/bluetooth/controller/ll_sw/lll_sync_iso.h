/*
 * Copyright (c) 2020-2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

struct lll_sync_iso {
	struct lll_hdr hdr;

	uint8_t seed_access_addr[4];
	uint8_t base_crc_init[2];

	uint16_t latency_prepare;
	uint16_t latency_event;
	uint16_t data_chan_prn_s;
	uint16_t data_chan_remap_idx;

	uint64_t payload_count:39;
	uint64_t enc:1;
	uint64_t ctrl:1;
	uint64_t cssn_curr:3;
	uint64_t cssn_next:3;

	uint8_t data_chan_map[5];
	uint8_t data_chan_count:6;
	uint8_t num_bis:5;
	uint8_t bn:3;
	uint8_t nse:5;
	uint8_t phy:3;

	uint32_t sub_interval:20;
	uint32_t max_pdu:8;
	uint32_t pto:4;

	uint32_t bis_spacing:20;
	uint32_t max_sdu:8;
	uint32_t irc:4;

	uint32_t sdu_interval:20;
	uint32_t irc_curr:4;
	uint32_t ptc_curr:4;
	uint32_t ptc:4;

	uint8_t bn_curr:3;
	uint8_t bis_curr:5;

	uint8_t term_reason;

	uint8_t ctrl_chan_use;
	uint16_t ctrl_instant;

	struct node_rx_pdu *payload[PDU_BIG_PAYLOAD_COUNT_MAX];
	uint8_t payload_count_max;
	uint8_t payload_head;
	uint8_t payload_tail;

	uint32_t window_widening_periodic_us;
	uint32_t window_widening_max_us;
	uint32_t window_widening_prepare_us;
	uint32_t window_widening_event_us;
	uint32_t window_size_event_us;
};

int lll_sync_iso_init(void);
int lll_sync_iso_reset(void);
void lll_sync_iso_create_prepare(void *param);
void lll_sync_iso_prepare(void *param);

extern uint8_t ull_sync_iso_lll_handle_get(struct lll_sync_iso *lll);
