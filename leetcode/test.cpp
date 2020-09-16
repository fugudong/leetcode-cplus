
if (retval != AWND_OK)
        return -1;
    else {
        awnd_update_eth_neigh_tbl(neigh_tbl,p->neigh_tbl, p->cnt, label, preconf_label);
    }
