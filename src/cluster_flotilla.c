
#include "server.h"
#include "cluster.h"

void flotilla_cluster_init(void);
unsigned long flotilla_connections_count(void);

void clusterInit(void) {
    flotilla_cluster_init();
}

void clusterInitListeners(void) {
    // No OP
}

void clusterCron(void) {
    // anything that is periodic and needs to happen within the main loop
    // one option for here is that it is a safe place to make changes to
    // the current cluster state. For instance, other functions in this
    // file return pointers to nodes. If those nodes need to be deleted,
    // they need to be deleted here and not at the convenience of the flotilla
    // thread
}

void clusterBeforeSleep(void) {
    // This function is executed before redis' main loop enters poll on its sockets.
    // Do anything urgent here
}

int verifyClusterConfigWithData(void) {
    // see documentation in cluster_legacy.c
    // In short, verify upon server startup that there are no contradicting conditions, e.g., some cached
    // or stored config/data does not match the cluster config or state
    return 1;
}

void clusterUpdateMyselfFlags(void) {
    /* Some flags (currently just the NOFAILOVER flag) may need to be updated
     * in the "myself" node based on the current configuration of the node,
     * that may change at runtime via CONFIG SET. This function changes the
     * set of flags in myself->flags accordingly. */
}

unsigned long getClusterConnectionsCount(void) {
    // I guess this will always be either 0 or 1
    return flotilla_connections_count();
}

void clusterUpdateMyselfHostname(void) {
    // NO OP - this is a config line and it does not seem to apply to us
}

void clusterUpdateMyselfAnnouncedPorts(void) {
    // NO OP - this is a config line and it does not seem to apply to us
}

void clusterUpdateMyselfIp(void) {
    // NO OP - this is a config line and it does not seem to apply to us
}

void clusterCommand(client *c) {
    // Oh yeah, we need to implement this. We need to decide where the C/Rust boundary is drawn here.
}

int clusterSendModuleMessageToTarget(const char *target, uint64_t module_id, uint8_t type, const char *payload, uint32_t len) {
    // Not supported. Return an error
    return 0;
}

void clusterPropagatePublish(robj *channel, robj *message, int sharded) {
    // not initially supported
}

void slotToChannelAdd(sds channel) {
    // not initially supported

}

void slotToChannelDel(sds channel) {
    // not initially supported
}

void freeThisNodesLink(clusterNode *node) {
    // NO OP
}

void freeNodeInboundLink(clusterNode *node) {
    // NO OP
}

sds clusterGenNodesDescription(client *c, int filter, int use_pport) {
    //need to implement
    return 0;
}

sds genClusterInfoString(void) {
    //need to implement
    return 0;
}

char* clusterNodeLastKnownIp(clusterNode *node) {
    //need to implement
    return 0;
}

int clusterNodePort(clusterNode *node) {
    //need to implement
    return 0;
}

clusterNode* clusterNodeGetSlaveof(clusterNode *node) {
    //need to implement
    return 0;
}

int clusterNodeConfirmedReachable(clusterNode* node) {
    //need to implement
    return 0;
}

int clusterNodeIsMaster(clusterNode* node) {
    //need to implement
    return 0;
}

int clusterNodeIsSlave(clusterNode* node) {
    //need to implement
    return 0;
}

int clusterNodeIsFailing(clusterNode* node) {
    //need to implement
    return 0;
}

int clusterNodeTimedOut(clusterNode* node) {
    //need to implement
    return 0;
}

int clusterNodeIsMyself(clusterNode* node) {
    //need to implement
    return 0;
}

int clusterNodeIsNoFailover(clusterNode* node) {
    //need to implement
    return 0;
}

clusterNode* getMyClusterNode(void) {
    //need to implement
    return 0;
}

clusterNode* getNodeBySlot(int slot) {
    //need to implement
    return 0;
}

clusterNode* getMigratingSlotDest(int slot) {
    //need to implement
    return 0;
}

clusterNode* getImportingSlotSource(int slot) {
    //need to implement
    return 0;
}

int isClusterHealthy(void) {
    //need to implement
    return 0;
}

uint16_t getClusterNodeRedirectPort(clusterNode* node, int use_pport) {
    //need to implement
    return 0;
}

const char *getPreferredEndpoint(clusterNode *n) {
    //need to implement
    return 0;
}

clusterNode *clusterLookupNode(const char *name, int length) {
    //need to implement
    return 0;
}

int isClusterManualFailoverInProgress(void) {
    return 0;
}
