#ifndef CLUSTER_LEGACY_H
#define CLUSTER_LEGACY_H

#include "server.h"

struct clusterNode;

/* clusterLink encapsulates everything needed to talk with a remote node. */
typedef struct clusterLink {
    mstime_t ctime;             /* Link creation time */
    connection *conn;           /* Connection to remote node */
    list *send_msg_queue;        /* List of messages to be sent */
    size_t head_msg_send_offset; /* Number of bytes already sent of message at head of queue */
    unsigned long long send_msg_queue_mem; /* Memory in bytes used by message queue */
    char *rcvbuf;               /* Packet reception buffer */
    size_t rcvbuf_len;          /* Used size of rcvbuf */
    size_t rcvbuf_alloc;        /* Allocated size of rcvbuf */
    struct clusterNode *node;   /* Node related to this link. Initialized to NULL when unknown */
    int inbound;                /* 1 if this link is an inbound link accepted from the related node */
} clusterLink;

/* Holds cluster node data specific to *this* cluster implementation. In the near
 * future we will have multiple clustering implementations.
 */
typedef struct clusterNodeData {
    unsigned long long last_in_ping_gossip; /* The number of the last carried in the ping gossip section */
    mstime_t ping_sent;      /* Unix time we sent latest ping */
    mstime_t pong_received;  /* Unix time we received the pong */
    mstime_t data_received;  /* Unix time we received any data */
    mstime_t fail_time;      /* Unix time when FAIL flag was set */
    mstime_t voted_time;     /* Last time we voted for a slave of this master */
    mstime_t repl_offset_time;  /* Unix time we received offset for this node */
    mstime_t orphaned_time;     /* Starting time of orphaned master condition */
    long long repl_offset;      /* Last known repl offset for this node. */
    char ip[NET_IP_STR_LEN];    /* Latest known IP address of this node */
    sds hostname;               /* The known hostname for this node */
    int port;                   /* Latest known clients port (TLS or plain). */
    int pport;                  /* Latest known clients plaintext port. Only used
                                   if the main clients port is for TLS. */
    int cport;                  /* Latest known cluster port of this node. */
    clusterLink *link;          /* TCP/IP link established toward this node */
    clusterLink *inbound_link;  /* TCP/IP link accepted from this node */
    list *fail_reports;         /* List of nodes signaling this as failing */
} clusterNodeData;

#define nodeData(node) ((clusterNodeData*)node->data)
#endif /* CLUSTER_LEGACY_H */
